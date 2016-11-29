<?php ## ��������� �������� ������ ����� �������� ����������.
// �������� "�� ��������" ��� ��������� ���������.
function takeVal($a) { $x = $a[1234]; }
// �������� "�� ������" ��� ��������� ���������.
function takeRef(&$a) { $x = $a[1234]; }
// �������� "�� ��������" � ���������� ���������.
function takeValAndModif($a) { $a[1234]++; }
// �������� "�� ������" � ���������� ���������.
function takeRefAndModif(&$a) { $a[1234]++; }

// ��������� ������ ������� �� ��������.
test("takeVal");
test("takeRef");
test("takeValAndModif");
test("takeRefAndModif");

function test($func) {
   // ������� ������� ������.
   $a = array();
   for ($i=1; $i<=100000; $i++) $a[$i] = $i;
   // ���� "������������" ������� (��� ��������).
   for ($t=time(); $t == time(); );
   // ��������� ������� � ������� ����� 1 �������.
   for ($N=0, $t=time(); time() == $t; $N++) $func($a);
   printf("<tt>$func</tt> took %d itr/sec<br>", $N);
}
?>