
// ���� �ʱ�ȭ
int WSAStartup( 
	WORD wVersionRequested, //���α׷��� �䱸�ϴ� �ֻ��� ���� ����. ���� 8��Ʈ�� �ֹ�����, ����� 8��Ʈ�� �� ������ �־ ����
	LPWSADATA IpWSAData // ������ �ü���� �����ϴ� ���� ������ ���� ������ ���� �� ����(���� ��� �� ��)
); //����:0 ����: �����ڵ�

// ���� ����
int WSACleanup(void); //����: 0, ����: SOCKET_ERROR

// ���� ����
SOCKET socket(
	int af, // �ּ� ü��: AF_INET(TCP or UDP) = 2, AF_INET6 = 23, AF_IrDA = 26, AF_BTH(�������) = 32
	int type, // ���� Ÿ��: SOCK_STREAM = �ŷڼ�o & ������, SOCK_DGRAM = �ŷڼ�x, �񿬰���
	int protocol // ��������
); //����: ���ο� ����, ����: INVALED_SOCKET

// ���� ����
int closesocket(
	SOCKET s
); //����: 0, ����: SOCKET_ERROR

// ���� ���� �ּ�ü - �⺻��
typedef struct sockaddr {
	unsigned short sa_family; // �ּ� ü�踦 ��Ÿ���� 16��Ʈ ���� �� ex) AF_INET / AF_INET6
	char	sa_data[15]; // �ش� �ּ� ü�迡�� ����� �ּ� ���� ex) IP�ּҿ� ��Ʈ ��ȣ
} SOCKADDR;

// SOCKADDR_IN ����ü - IPv4 ����
typedef struct sockaddr_in {
	short			sin_family; // AF_INET
	unsigned short	sin_port; // ��Ʈ ��ȣ
	struct in_addr	sin_addr; // IPv4 �ּ�
	char			sin_zero[8]; // 0���� ����
} SOCKADDR_IN;

// ����Ʈ ���� �Լ�(���� Ȯ��)
int WSAHtons(SOCKET s, unsigned short hostshort, unsigned short *Ipnetshort);
int WSAHtonl(SOCKET s, unsigned long hostlong, unsigned long *IPnetlong);
int WSAHtons(SOCKET s, unsigned short netshort, unsigned short *Iphostshort);
int WSAHtonl(SOCKET s, unsigned long netlong, unsigned long *IPhostlong);

// IP �ּ� ��ȯ �Լ�(���ڿ� -> ����)
int WSAStingToAddress(
	LPTSTR AddressStirng, // ���ڿ� ������ IP �ּ�
	INT AddressFamily, // AF_INET �Ǵ� AF_INET6
	LPWSAPROTOCOL_INFO IpProtocolInfo, // NULL
	LPSOCKADDR IpAddress, // IP �ּ�(����)�� ������ ����ü; SOCKADDR_IN
	LPINT IpAddressLength // �ּ� ����ü�� ����
);

// IPv4 �Ǵ� IPv6 �ּ� ��ȯ �Լ�(���� -> ���ڿ�)
int WSAAddressToString(
	LPSOCKADDR IpsaAddress, // ���� ������ IP �ּ�; SOCKADDR_IN �Ǵ� SOCKADDR_IN6
	DWORD dwAddressLength, // �ּ� ����ü�� ����
	LPWSAPROTOCOL_INFO IpProtocolInfo, // NULL
	LPTSTR IpszAddressString, // IP �ּ�(���ڿ�)�� ������ ����
	LPDWORD IpdwAddressStringLength // ������ ����
);

// ������ �̸� <-> IP �ּ� ��ȯ �Լ�
