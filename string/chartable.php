<?php ## ������ ���� ������� ASCII-��������.
// ������� ������� ������ ����, ��� �� ���������� ��������,
// �� �������� � �������������� (�������) ����������
for ($i=0,$x=0; $x<16; $x++) {
  for ($y=0; $y<16; $y++) {
    $chars[$x][$y] = array($i, chr($i));
    $i++;
  }
}
// ������ ������� ����������� ����������, ��������� ��������� 
// ������� �������� ���� � HTML-��������
?>
<table border=1 cellpadding=1 cellspacing=0>
<?php foreach ($chars as $row) {?>
  <tr>
  <?php foreach ($row as $cell) { ?>
    <td>
      <?=$cell[0]?>:	
      <b><tt><?=$cell[1]?></tt></b>
    </td>
  <?php }?>
  </tr>
<?php }?>
</table>
