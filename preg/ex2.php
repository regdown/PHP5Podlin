<?php ## ������ ������.
// ����� � ������ ����� E-mail. \S �������� "�� ������", � [a-z0-9.]+ -
// "����� ����� ����, ���� ��� �����". ����������� 'i' ����� '/'
// ���������� PHP �� ��������� ������� ���� ��� ������ ����������.
// ����������� 's', ������� ����� � 'i', �������, ��� �� ��������
// � "������������ ������" (��. ���� � ���� �����).
preg_match('/(\S+)@([a-z0-9.]+)/is', "������ �� somebody@mail.ru!", $p);
// ��� ����� ����� � $p[2], � ��� ����� (�� @) - � $p[1].
echo "� ������ �������: ���� - $p[1], ���� - $p[2]";
?>