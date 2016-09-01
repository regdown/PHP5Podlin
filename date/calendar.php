<?php ## ��������� �� ������� �����.

// ������� ��������� ��������� ������, �������������� �����
// ��������� �� ��������� ����� � ���. ������ ������� �� �����,
// ��������������� �������. ������ ������ - ������ �� ���� 
// ���������, ������� ����� ������ (��� ������ ������, ����
// ������ ������ ��������� �����).
function makeCal($year, $month) {
  // �������� ����� ��� ������ ��� 1 ����� ������. ������������ 
  // ���, ����� ����������� ��������������� ����� 7, � �� ����� 0.
  $wday = JDDayOfWeek(GregorianToJD($month, 1, $year), 0);
  if ($wday == 0) $wday = 7;
  // �������� � ����� ����� � ������ (���� ������ ���� 
  // ��� ������ ����� ������, ����� � ��������� ����� �������).
  $n = - ($wday - 2);
  $cal = array();
  // ���� �� �������.
  for ($y=0; $y<6; $y++) {
    // ������� ������. ������� �����.
    $row = array();
    $notEmpty = false;
    // ���� ������ ������ �� ���� ������.
    for ($x=0; $x<7; $x++, $n++) {
      // ������� ����� >0 � < ����� ������?
      if (checkdate($month, $n, $year)) {
        // ��. ��������� ������.
        $row[] = $n;
        $notEmpty = true;
      } else {
        // ���. ������ �����.
        $row[] = "";
      }
    }
    // ���� � ������ ������ ��� �� ������ ��������� ��������,
    // ������, ����� ��������.
    if (!$notEmpty) break;
    // ��������� ������ � ������.
    $cal[] = $row;
  }
  return $cal;
}

// ��������� ��������� �� ������� �����.
$now = getdate();
$cal = makeCal($now['year'], $now['mon']-1);
?>
<!-- ������ ������ ���������. -->
<table border=1>
  <tr>
    <td>��</td>
    <td>��</td>
    <td>��</td>
    <td>��</td>
    <td>��</td>
    <td>��</td>
    <td style="color:red">��</td>
  </tr>
  <!-- ���� �� ������� -->
  <?foreach ($cal as $row) {?>
    <tr>
      <!-- ���� �� ������� -->
      <?foreach ($row as $i=>$v) {?>
        <!-- ����������� - "�������" ���� -->
        <td style="<?=$i==6? 'color:red' : ''?>">
          <?=$v? $v : "&nbsp;"?>
        </td>
      <?}?>
    </tr>
  <?}?>
</table>
