<?php ## ������� �������� ����� �������������� �������� � �����
/**
 * ��������� ����� ������ � �������� �� ������� �����.
 *
 * @param int $code ����� ������
 *
 * $return ����� ��������
*/
function domexeptionmessage($code)
{
    $rusmes=Array(
    DOM_INDEX_SIZE_ERR
	=> "������ ����������� ��� ������ ����������� ��������",
    DOMSTRING_SIZE_ERR
	=> "������ � ������� ������ ���� DOMSTRING",
    DOM_HIERARCHY_REQUEST_ERR
	=> "���� ����������� � �����, � �������� �� �� �����������",
    DOM_WRONG_DOCUMENT_ERR
	=> "���� ������������ � ���������, � �������� �� �� �����������",
    DOM_INVALID_CHARACTER_ERR
	=> "� ����� ������������ ����������� ������",
    DOM_NO_DATA_ALLOWED_ERR
	=> "� ���� ����������� ������, ������� �� �� ����� ���������",
    DOM_NO_MODIFICATION_ALLOWED_ERR
	=> "������� ����������� ����, ������� �� ������ ���� �������",
    DOM_NOT_FOUND_ERR
	=> "������ � ���� � ������ ��������� ����������",
    DOM_NOT_SUPPORTED_ERR
	=> "���������� �� ������������ ������ ������ ��� �������� ",
    DOM_INUSE_ATTRIBUTE_ERR
	=> "������� �������� �������, ������� ��� ������������",
    DOM_INVALID_STATE_ERR   //DOM2
	=> "������� ������������ ����������� ������",
    DOM_SYNTAX_ERR          //DOM2
	=> "������ �������� ������",
    DOM_INVALID_MODIFICATION_ERR    //DOM2
	=> "������� ��������� ���� �������",
    DOM_NAMESPACE_ERR       //DOM2
       => "������� ��� �������� ������ � ������ ������� ���� ����������",
    DOM_INVALID_ACCESS_ERR  //DOM2
	=> "�������� ��� �������� �� ��������� � ������� �������",
    DOM_VALIDATION_ERR      //DOM3
	=> "������� ���������� ��� �������� ���� �������� �
     ������������� ���������",
    );
    $message=@$rusmes[$code];
    if (!$message)
	$message("����������� ��� ������ $code");
    return $message."\r\n";
}
