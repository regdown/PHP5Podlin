<!-- �������������� ��������� if-else. -->
<?if (isset($_REQUEST['go'])):?>
  ������, <?=$_REQUEST['name']?>!
<?else:?>
  <form action="<?=$_SERVER['REQUEST_URI']?>" method=post>
  ���� ���: <input type=text name=name><br>
  <input type=submit name=go value="��������!">
<?endif?>
