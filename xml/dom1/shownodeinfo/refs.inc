<?php ## ������� ������������ ������ �������� ����������� ����
/**
 * ������������ ����� �� ������������� ��������
 *
 * @return string �����, ����������� ������������ �������
 */
function ParentRef()
{
    global $path; //����� �� ������������� ����
    $nodepath=$path;
    $n=strrpos($path,'/');  //������� ���������� ������� /
    if ($n >= 0)
	$nodepath=substr($path,0,$n);
    return ($nodepath);
}

/**
 * ������������ ����� �� ���������� ����
 *
 * @return string �����, ����������� ��������� ����
 */
function NextSiblingRef()
{
    global $path; //����� �� ������������� ����
    $nodepath=$path;
    $n=strrpos($path,'/');  //������� ���������� ������� /
    if ($n >= 0) {
	$n++;
	if (substr($path,$n,1)=='@') $n++; //���� ��������
	$parentpath=substr($path,0,$n);     //���� �� ��������
	$local=substr($path,$n);  //����� � ������
	$nodepath="$parentpath".($local+1);
    }
    return ($nodepath);
}

/**
 * ������������ ����� �� ����������� ����
 *
 * @return string �����, ����������� ���������� ����
 */
function PreviousSiblingRef() {
    global $path; //����� �� ������������� ����
    $n=strrpos($path,'/');  //������� ���������� ������� /
    $nodepath=$path;
    if ($n >= 0) {
	$n++;
	if (substr($path,$n,1)=='@') $n++; //���� ��������
	$parentpath=substr($path,0,$n);     //���� �� ��������
	$local=substr($path,$n);  //����� � ������
	$nodepath="$parentpath".($local-1);
    }
    return ($nodepath);
}

/**
 * ������������ ����� �� ������� ��������� ��������
 *
 * @return string �����, ����������� ������ �������� �������
 */
function FirstChildRef()
{
    global $path; //����� �� ������������� ����
    $nodepath=$path;
    $nodepath.="/1";
    return ($nodepath);
}

/**
 * ������������ ����� �� ���������� ��������� ��������
 *
 * @param int $nlast ����� ���������� ��������� ��������
 *
 * @return string �����, ����������� ��������� �������� �������
 */
function LastChildRef($nlast)
{
    global $path; //����� �� ������������� ����
    $nodepath=$path;
    $nodepath.="/$nlast";
    return ($nodepath);
}

/**
 * ������������ ����� �� ��������� �������� $num
 *
 * @param int $num ����� ��������� ����
 *
 * @return string �����, ����������� �������� ������� $num
 */
function ChildRef($num)
{
    global $path; //����� �� ������������� ����
    $nodepath="$path/".($num+1); //0-� ������� ���������� ��� 1-�
    return ($nodepath);
}

/**
 * ������������ ����� �� �������� $num
 *
 * @param int $num ����� ��������
 *
 * @return string �����, ����������� �� ������� $num
 */
function AttrRef($num)
{
    global $path; //����� �� ������������� ����
    $nodepath="$path/@".($num+1);
    return ($nodepath);
}
?>
