//beijing_waswai.h  ����������

RESIDENT_BEGIN(CRbeijing_waswai);

virtual void create()
{
	set_name( "������");
	set("resident", "����");

	add_door("��������", "��������", "����������");
	add_door("����", "��������", "����������");
};

RESIDENT_END;
