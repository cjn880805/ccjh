//junying.h  ��Ӫ
//�ز� 2002��12��9

ROOM_BEGIN(CRGuanWai_junying);

virtual void create()			
{
	set_name("��Ӫ");

	set("renwu", 1);

	add_door("����ͷ", "��������ͷ", "�����Ӫ");
	add_door("���ȷ�Ӫ��", "�������ȷ�Ӫ��1", "�����Ӫ");
	add_door("�о��ȷ�Ӫ��", "�����о��ȷ�Ӫ��1", "�����Ӫ");
	add_door("���ȷ�Ӫ��", "�������ȷ�Ӫ��1", "�����Ӫ");

};

ROOM_END;
