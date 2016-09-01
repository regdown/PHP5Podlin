<?php ## ��������� ���������� ���� � ������.
// ��� ������� �������� �� ������ � $text ��� ���������� ����� �
// ���������� �� ������. � �������������� �������� $nOrigWords 
// ���������� �������� ����� ���� � ������, ������� ���� �� 
// "����������" ����������.
function getUniques($text, &$nOrigWords=false) { 
  // ������� �������� ��� ����� � ������.
  $words = preg_split("/([^[:alnum:]]|['-])+/s", $text);
  $nOrigWords = count($words);
  // ����� �������� ����� � ������� ��������.
  $words = array_map("strtolower", $words);
  // �������� ���������� ��������.
  $words = array_unique($words);
  return $words;
}
// ������ ���������� �������.
setlocale(LC_ALL, '');
$fname = "largetextfile.txt";
$text = file_get_contents($fname);
$uniq = getUniques($text, $nOrig);
echo "���� ����: $nOrig<br>";
echo "����� ����: ".count($uniq)."<hr>";
echo join(" ", $uniq);
?>
