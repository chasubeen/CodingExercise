/* ���ڿ����� ���� F�� �˻��ϴ� ���α׷� */
#include<stdio.h>

/* --- ���ڿ� s���� ���� c�� �˻��ϴ� �Լ� --- */
int str_chr(const char* s, int c) {
	int i = 0;
	c = (char)c;
	while (s[i] != c) {
		if (s[i] == '\0') // �˻� ����
			return -1;
		i++;
	}
	return i; // �˻� ����
}

void main() {
	char str[64]; // �� ���ڿ����� �˻�
	char tmp[64];
	int ch; // �˻��� ����
	int idx;

	printf("���ڿ�: ");
	scanf("%s", str); 

	printf("�˻��� ����: ");
	scanf("%s", tmp); // ���� ���ڿ��� �˻��� ���ڸ� �о� ����
	ch = tmp[0]; // ù ��° ���ڸ� �˻��� ���ڷ� ����

	if ((idx = str_chr(str, ch)) == -1) // ó�� ������ ���ڸ� �˻�
		printf("���� '%c'��(��) ���ڿ��� �����ϴ�.\n", ch);
	else
		printf("���� '%c'��(��) %d��°�� �ֽ��ϴ�.\n", ch, idx + 1);
}