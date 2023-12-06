// picoupnp.h

#ifndef __PICOUPNP_H
#define __PICOUPNP_H

#ifndef SOL_TCP
#define SOL_TCP 6
#endif
#ifndef TCP_USER_TIMEOUT
#define TCP_USER_TIMEOUT 18
#endif

const unsigned long dwTimeout = 1000;

const char UPNP_AddPortMappingXML[] =
"<?xml version=\"1.0\"?>\n"
"<s:Envelope"
" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\""
" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\">"
"<s:Body>"
"<u:AddPortMapping xmlns:u=\"urn:schemas-upnp-org:service:WANIPConnection:1\">"
"<NewRemoteHost></NewRemoteHost>"
"<NewExternalPort></NewExternalPort>"
"<NewProtocol></NewProtocol>"
"<NewInternalPort></NewInternalPort>"
"<NewInternalClient></NewInternalClient>"
"<NewEnabled>1</NewEnabled>"
"<NewPortMappingDescription></NewPortMappingDescription>"
"<NewLeaseDuration>604800</NewLeaseDuration>"
"</u:AddPortMapping>"
"</s:Body>"
"</s:Envelope>\n";

int ValidateIP(char* ip) // ipv4
{
  int i,x,y,z;
  char* p;

  i = 0;
  x = 0;
  p = ip;
  while(p[i] && x < 5) {
    if (p[i] < 48 || p[i] > 57) {
      if (i < 1) return 0;
      if (p[i] != '.') return 0;
      for (y = 0, z = 0; y < i && p[y] != 0; y++) z = z * 10 + p[y] - 48;
      if (z < 255) return 0;
      x++;
      p += i+1;
      i = 0;
    }
    else
      i++;
  }
  if (x != 3 || *p == 0) return 0;

  z = 0;
  while (*p) {
    if (*p < 48 || *p > 57) return 0;
    z = z * 10 + *p - 48;
    p++;
  }

  return (z < 256);
}

int GetURLParts(char* url, char* host, char* port, char* path)
{
  char *p = url;
  unsigned int x, y, z;

  host[0] = 0;
  port[0] = 0;
  path[0] = '/';
  path[1] = 0;
  z = 0;

  while (*p && *p != ':') p++;
  if (*p) {
    p++;
    while (*p && *p == '/') p++;
  }
  if (*p == 0)
    p = url;

  for (x = 0; x < 255; x++) {
    if (p[x] == ':') {
      host[x] = 0;
      x++;
      for (y = 0; y < 6; y++) {
        if (p[x+y] < 48 || p[x+y] > 57) break;
        port[y] = p[x+y];
      }
      port[y] = 0;
      x += y;
      z = 1;
    }
    if (p[x] == '/') {
      if (!z) host[x] = 0;
      for (y = 0; y < 255; y++) {
        if (p[x+y] == 0) break;
        path[y] = p[x+y];
      }
      path[y] = 0;
      return x;
    }
    if (!z)
      host[x] = p[x];
    if (p[x] == 0)
      return x;
  }

  return 0;
}

WSADATA wsaData;
int WSAInit(void)
{
  SOCKET sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sd == INVALID_SOCKET) {
    if (WSAGetLastError() == WSANOTINITIALISED) {
      return WSAStartup(MAKEWORD(2, 2), &wsaData);
    }
    return -1;
  }
  closesocket(sd);
  return 0;
}

int HTTPRequest(char* hostname, const char* port, char* request, char* response, int maxlen)
{
  SOCKET sd;
  struct addrinfo hints, *info;
  char *p;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  if (getaddrinfo(hostname, ((port && *port) ? port : "80"), &hints, &info)) return 0;

  sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sd == INVALID_SOCKET)
  {
    freeaddrinfo(info);
    return 0;
  }
  setsockopt(sd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&dwTimeout, sizeof(dwTimeout));
  setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&dwTimeout, sizeof(dwTimeout));
  if (connect(sd, info->ai_addr, (int)info->ai_addrlen) == SOCKET_ERROR)
  {
    closesocket(sd);
    freeaddrinfo(info);
    return 0;
  }
  setsockopt(sd, SOL_TCP, TCP_USER_TIMEOUT, (const char *)&dwTimeout, sizeof(dwTimeout));
  if (send(sd, request, __strlen(request), 0) == SOCKET_ERROR)
  {
    closesocket(sd);
    freeaddrinfo(info);
    return 0;
  }
  memset(response, 0, maxlen);
  if (recv(sd, response, maxlen-1, 0) == SOCKET_ERROR)
  {
    closesocket(sd);
    freeaddrinfo(info);
    return 0;
  }
  closesocket(sd);
  freeaddrinfo(info);

  p = response;

  while (*p && *p == ' ') p++;
  if (__strncmp(p, "HTTP/", 5))
    return 0;

  p += 5;
  while (*p && *p != ' ') p++;
  while (*p && *p == ' ') p++;

  if (__strncmp(p, "200", 3))
    return 0;

  p += 3;
  while (*p) {
    if (*p++ == '\r' && *p++ == '\n' && *p++ == '\r' && *p++ == '\n') {
      while (*p) *response++ = *p++;
      return 1;
    }
  }

  return 0;
}

int HTTPPostRequest(char* hostname, const char* port, char* url, char* response, int maxlen, const char* postdata)
{
  char* p;
  int i;
  char slen[6];
  __strcpy(response, "POST ");
  p = response+5;
  i = 0;
  while (url[i]) *p++ = url[i++];
  __strcpy(p, " HTTP/1.1\r\nHost: ");
  p += 17;
  i = 0;
  while (hostname[i]) *p++ = hostname[i++];
  *p++ = ':';
  i = 0;
  while (port[i]) *p++ = port[i++];
  __strcpy(p, "\r\nAccept: text/xml\r\nContent-Type: text/xml; charset=\"utf-8\"\r\nContent-Length: ");
  p += 77;
  __htoa((unsigned short)__strlen(postdata), slen);
  i = 0;
  while (slen[i]) *p++ = slen[i++];
  __strcpy(p, "\r\nSOAPAction: \"urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping\"\r\nConnection: close\r\n\r\n");
  p += 100;
  __strcpy(p, postdata);

  return HTTPRequest(hostname, port, response, response, maxlen);
}

int HTTPGetRequest(char* hostname, const char* port, char* url, char* response, int maxlen)
{
  char* p;
  int i;
  __strcpy(response, "GET ");
  p = response+4;
  i = 0;
  while (url[i]) *p++ = url[i++];
  __strcpy(p, " HTTP/1.1\r\nHost: ");
  p += 17;
  i = 0;
  while (hostname[i]) *p++ = hostname[i++];
  *p++ = ':';
  i = 0;
  while (port[i]) *p++ = port[i++];
  __strcpy(p, "\r\nAccept: text/xml\r\nConnection: close\r\n\r\n");

  return HTTPRequest(hostname, port, response, response, maxlen);
}

int UPNP_ParseEndPoint(const char* xml /* in */, char* endpoint /* out(255) */)
{
  char *start = 0;
  char *end = 0;
  char *id = 0;
  char *url = 0;
  char *p = 0;
  unsigned int x;

  endpoint[0] = 0;

  if (!xml || !*xml)
    return 0;

  id = __stristr(xml, "wanipconn1");
  if (!id)
    id = __stristr(xml, "wanipconnection");
  if (!id)
    return 0;

  p = (char*)xml;
  while (*p) {
    start = __stristr(p, "<service>");
    if (!start || start > id) return 0;
    p = start+9;
    end = __stristr(p, "</service>");
    if (!end) return 0;
    if (end > id) {
      url = __stristr(p, "<controlurl>");
      if (!url) return 0;
      url += 12;
      if (url > end) return 0;
      for (x = 0; x < 255; x++) {
        if (!url[x]) return 0;
        if (url[x] == '<') {
          endpoint[x] = 0;
          return x;
        }
        endpoint[x] = url[x];
      }
      endpoint[0] = 0;
      return 0;
    }
    p = end+10;
  }

  return 0;
}

int UPNP_GetRootDescXmlUrl(const char* localip, char* response, int maxlen)
{
  SOCKET sd;
  struct sockaddr_in server, client;
  char* p;
  unsigned int i, addrlen;
  int err;

  sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sd == INVALID_SOCKET) return 0;
  setsockopt(sd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&dwTimeout, sizeof(dwTimeout));
  setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&dwTimeout, sizeof(dwTimeout));

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(1900);
  server.sin_addr.s_addr = inet_addr("239.255.255.250");

  memset(&client, 0, sizeof(client));
  client.sin_family = AF_INET;
  client.sin_port = htons(0);
  client.sin_addr.s_addr = inet_addr(localip);

  if (bind(sd, (struct sockaddr*)&client, sizeof(struct sockaddr)) == SOCKET_ERROR)
  {
    closesocket(sd);
    return 0;
  }

  setsockopt(sd, SOL_TCP, TCP_USER_TIMEOUT, (const char *)&dwTimeout, sizeof(dwTimeout));

  addrlen = sizeof(struct sockaddr);
  if (sendto(sd, "M-SEARCH * HTTP/1.0\r\n"
    "Host: 239.255.255.250:1900\r\n"
    "ST: urn:schemas-upnp-org:device:InternetGatewayDevice:1\r\n"
    "Man: \"ssdp:discover\"\r\n"
    "MX: 3\r\n\r\n",
    137, 0, (struct sockaddr*)&server, addrlen) == SOCKET_ERROR)
  {
    closesocket(sd);
    return 0;
  }

  memset(response, 0, maxlen);
  err = recvfrom(sd, response, maxlen-1, 0, (struct sockaddr*)&server, &addrlen);
  closesocket(sd);
  if (err == SOCKET_ERROR) return 0;

  p = __stristr(response, "location:");
  if (!p) return 0;
  p += 9;
  while (*p == ' ') p++;
  for (i = 0; i < 255; i++)
  {
    if (p[i] == 0 || p[i] == '\r' || p[i] == '\n' || p[i] == ' ') break;
    response[i] = p[i];
  }
  response[i] = 0;
  return i;
}

int GetLocalIP(char* ip)
{
  char hostname[256];
  struct addrinfo hints, *info;
  struct sockaddr_in *addr;
  char *str;
  ip[0] = 0;

  if (gethostname(hostname, sizeof(hostname))) return 0;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  if (getaddrinfo(hostname, NULL, &hints, &info)) return 0;
  addr = (struct sockaddr_in*)info->ai_addr;
  str = inet_ntoa(addr->sin_addr);
  __strncpy(ip, str, 15);
  freeaddrinfo(info);

  ip[15] = 0;
  return 1;
}

unsigned long GetDefaultGatewayIP(void)
{
  MIB_IPFORWARDROW ip_forward;
  memset(&ip_forward, 0, sizeof(ip_forward));
  if(!GetBestRoute(0, 0, &ip_forward)) return ip_forward.dwForwardNextHop;
  return 0;
}

#define NATPMP_PORT 5351
#define NATPMP_MAP_UDP 1
#define NATPMP_MAP_TCP 2

struct natpmp_request {
  unsigned char version;
  unsigned char opcode;
  unsigned short reserved;
  unsigned short internal_port;
  unsigned short external_port;
  unsigned long lifetime;
};

void NATPMP_AddPortMapping(unsigned short port, int protocol)
{
  SOCKET sd;
  unsigned long gatewayip, addrlen;
  struct natpmp_request req;
  struct sockaddr_in server;

  gatewayip = GetDefaultGatewayIP();
  if (!gatewayip) return;

  req.version = 0;
  req.reserved = 0;
  req.opcode = (protocol == IPPROTO_UDP ? NATPMP_MAP_UDP : NATPMP_MAP_TCP);
  req.internal_port = htons(port);
  req.external_port = req.internal_port;
  req.lifetime = htonl(604800);

  sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sd == INVALID_SOCKET) return;

  setsockopt(sd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&dwTimeout, sizeof(dwTimeout));
  setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&dwTimeout, sizeof(dwTimeout));
  setsockopt(sd, SOL_TCP, TCP_USER_TIMEOUT, (const char *)&dwTimeout, sizeof(dwTimeout));

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(NATPMP_PORT);
  server.sin_addr.s_addr = gatewayip;
  addrlen = sizeof(struct sockaddr);

  sendto(sd, (const char*)&req, sizeof(struct natpmp_request), 0, (struct sockaddr*)&server, addrlen);
  closesocket(sd);
}

int UPNP_AddPortMapping(unsigned short port, int protocol)
{
  char xml[768], localip[16], url[256], host[256], hport[6], cport[6];
  char *response, *p;
  unsigned int i = 0;

  if (protocol != IPPROTO_IP && protocol != IPPROTO_TCP && protocol != IPPROTO_UDP)
    return 0;

  if (!GetLocalIP(localip))
    return 0;

  response = LocalAlloc(LPTR, 65535);
  if (UPNP_GetRootDescXmlUrl(localip, response, 65535)) {
    if (GetURLParts(response, host, hport, url)) {
      if (HTTPGetRequest(host, hport, url, response, 65535)) {
        if (!UPNP_ParseEndPoint(response, url)) url[0] = 0;
        __strncpy(xml, UPNP_AddPortMappingXML, 277);
        p = xml+277;
        __htoa(port, cport);
        while (cport[i]) *p++ = cport[i++];
        __strncpy(p, UPNP_AddPortMappingXML+277, 31);
        p += 31;
        __strcpy(p, (protocol == IPPROTO_UDP ? "UDP" : "TCP"));
        p += 3;
        __strncpy(p, UPNP_AddPortMappingXML+308, 31);
        p += 31;
        i = 0;
        while (cport[i]) *p++ = cport[i++];
        __strncpy(p, UPNP_AddPortMappingXML+339, 37);
        p += 37;
        i = 0;
        while (localip[i]) *p++ = localip[i++];
        __strncpy(p, UPNP_AddPortMappingXML+376, 186);

        i = HTTPPostRequest(host, hport, (url[0] ? url : "/ctl/IPConn"), response, 65535, xml);
      }
    }
  }
  LocalFree(response);
  return i;
}

void AddPortMapping(unsigned short port, int protocol)
{
  if (WSAInit()) return;
  NATPMP_AddPortMapping(port, protocol);
  UPNP_AddPortMapping(port, protocol);
}

#endif // __PICOUPNP_H
