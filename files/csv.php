<?php ## ������ CSV-�����.
$f = fopen("file.csv", "rt") or die("������!");
for ($i=0; $data=fgetcsv($f,1000,";"); $i++) {
  $num = count($data);
  echo "<h3>������ ����� $i (�����: $num):</h3>";
  for ($c=0; $c<$num; $c++)
    print "[$c]: $data[$c]<br>"; 
}
fclose($f);
?>