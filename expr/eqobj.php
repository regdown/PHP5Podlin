<?php ## ��������� ��������� � ���������������.
class AgentSmith {}
$smit = new AgentSmith();
$wesson = new AgentSmith();
if ($smit == $wesson) echo "������� �����.";
if ($smit === $wesson) echo "������� ������������.";
?>
