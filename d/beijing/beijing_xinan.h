//beijing_xinan.h

//Sample for room:  ��������
//coded by Fisho
//data: 2000-11-2

RESIDENT_BEGIN(CRbeijing_xinan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "����");

	//add npcs into the room

	add_npc("pub_jinxilaoren");
	add_npc("pub_boy");
	add_npc("pub_playboy");
	add_npc("shaolin_tuoboseng");

	add_door("��������", "��������", "��������");
	add_door("�����ʳ�", "�����ʳ�", "��������");
	
	add_door("�������", "�������", "��������");
	add_door("�����͵�2", "�����͵�2", "��������");
	add_door("����������","����������", "��������");
	add_door("�����ӻ���", "�����ӻ���", "��������");
	add_door("�����ײĵ�", "�����ײĵ�", "��������");
	add_door("��������ϷԺ", "��������ϷԺ", "��������");
	add_door("�����ش���ҩ��", "�����ش���ҩ��", "��������");

};

RESIDENT_END;
