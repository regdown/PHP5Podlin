<?php ## ������� �������� ����� �� ��������� KOI8-R � UTF-8 � �������
setlocale(LC_ALL,"ru_RU.koi8r");

//����������� ��������� ���������
define('Encoding','KOI8-R');

//��������� XML-���������
define ('XMLHead',"<?xml version='1.0' encoding='".Encoding."'?>");

/**
 * �������������� ������ � ��������� UTF-8
 *
 *  @param string str    �������������� ������
 *  @param string encode �������� ��������� (�� ��������� KOI8-R)
 *
 * @return  ���������������� ������ � ��������� UTF-8
 */
function utf8encode($str,$encode=Encoding)
{
    return iconv($encode,'UTF-8',$str);
}

/**
 * �������������� ������ �� ��������� UTF-8
 *
 *  @param string str    �������������� ������ � ��������� UTF-8
 *  @param string encode ������� ��������� (�� ��������� KOI8-R)
 *
 * @return  ���������������� ������ � ��������� ���������
 */
function utf8decode($str,$encode=Encoding)
{
    return iconv('UTF-8',$encode,$str);
}
?>
