<?php ## ������ �� �������.
// ��������� ����� �����.
class AgentSmith {}
// ������� ����� ������ ������ AgentSmith.
$first = new AgentSmith();
// ����������� �������� �������� ������.
$first->mind = 0.123;
// �������� �������. 
$second = $first;
// �������� "����������" � �����!
$second->mind = 100;
// ������� ��� ��������.
echo "First mind: {$first->mind}, second: {$second->mind}";
print_r($second, true);
?>
