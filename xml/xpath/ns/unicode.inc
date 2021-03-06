<?php ## ������� �������� ����� �� ��������� WINDOWS-1251 � UTF-8 � �������
setlocale(LC_ALL,"ru_RU.CP1251");

//����������� ��������� ���������
define('Encoding','WINDOWS-1251');

//��������� XML-���������
define ('XMLHead',"<?xml version='1.0' encoding='".Encoding."'?>");

/**
 * �������������� ������ � ��������� UTF-8
 *
 *  @param string str    �������������� ������
 *  @param string encode �������� ��������� (�� ��������� WINDOWS-1251)
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
 *  @param string encode ������� ��������� (�� ��������� WINDOWS-1251)
 *
 * @return  ���������������� ������ � ��������� ���������
 */
function utf8decode($str,$encode=Encoding)
{
    return iconv('UTF-8',$encode,$str);
}
?>
