
// 윈속 초기화
int WSAStartup( 
	WORD wVersionRequested, //프로그램이 요구하는 최상위 윈속 버전. 하위 8비트에 주버전을, 사우이 8비트에 부 버전을 넣어서 전달
	LPWSADATA IpWSAData // 윈도우 운영체제가 제공하는 윈속 구현에 관한 정보를 얻을 수 있음(거의 사용 안 함)
); //성공:0 실패: 오류코드

// 윈속 종료
int WSACleanup(void); //성공: 0, 실패: SOCKET_ERROR

// 소켓 생성
SOCKET socket(
	int af, // 주소 체계: AF_INET(TCP or UDP) = 2, AF_INET6 = 23, AF_IrDA = 26, AF_BTH(블루투스) = 32
	int type, // 소켓 타입: SOCK_STREAM = 신뢰성o & 연결형, SOCK_DGRAM = 신뢰성x, 비연결형
	int protocol // 프로토콜
); //성공: 새로운 소켓, 실패: INVALED_SOCKET

// 소켓 종료
int closesocket(
	SOCKET s
); //성공: 0, 실패: SOCKET_ERROR

// 소켓 구조 주소체 - 기본형
typedef struct sockaddr {
	unsigned short sa_family; // 주소 체계를 나타내는 16비트 정수 값 ex) AF_INET / AF_INET6
	char	sa_data[15]; // 해당 주소 체계에서 사용할 주소 정보 ex) IP주소와 포트 번호
} SOCKADDR;

// SOCKADDR_IN 구조체 - IPv4 전용
typedef struct sockaddr_in {
	short			sin_family; // AF_INET
	unsigned short	sin_port; // 포트 번호
	struct in_addr	sin_addr; // IPv4 주소
	char			sin_zero[8]; // 0으로 설정
} SOCKADDR_IN;

// 바이트 정렬 함수(윈속 확장)
int WSAHtons(SOCKET s, unsigned short hostshort, unsigned short *Ipnetshort);
int WSAHtonl(SOCKET s, unsigned long hostlong, unsigned long *IPnetlong);
int WSAHtons(SOCKET s, unsigned short netshort, unsigned short *Iphostshort);
int WSAHtonl(SOCKET s, unsigned long netlong, unsigned long *IPhostlong);

// IP 주소 변환 함수(문자열 -> 숫자)
int WSAStingToAddress(
	LPTSTR AddressStirng, // 문자열 형식의 IP 주소
	INT AddressFamily, // AF_INET 또는 AF_INET6
	LPWSAPROTOCOL_INFO IpProtocolInfo, // NULL
	LPSOCKADDR IpAddress, // IP 주소(숫자)를 저장할 구조체; SOCKADDR_IN
	LPINT IpAddressLength // 주소 구조체의 길이
);

// IPv4 또는 IPv6 주소 변환 함수(숫자 -> 문자열)
int WSAAddressToString(
	LPSOCKADDR IpsaAddress, // 숫자 형식의 IP 주소; SOCKADDR_IN 또는 SOCKADDR_IN6
	DWORD dwAddressLength, // 주소 구조체의 길이
	LPWSAPROTOCOL_INFO IpProtocolInfo, // NULL
	LPTSTR IpszAddressString, // IP 주소(문자열)를 저장할 버퍼
	LPDWORD IpdwAddressStringLength // 버퍼의 길이
);

// 도메인 이름 <-> IP 주소 변환 함수
