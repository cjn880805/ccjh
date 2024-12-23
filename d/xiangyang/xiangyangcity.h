//XiangYangCity.h

//Sample for room: Xiang Yang City
//coded by Lanwood
//data: 2000-10-25

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXiangYangCity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
//	add_npc("animal_lion");
//	add_npc("animal_laofu");

	add_npc("honghua_lilishi");
	add_npc("gaibang_wuxiuwen");
	add_npc("gaibang_shitianjing");
	add_npc("xiangyang_wusantong");  
	add_npc("xiangyang_guofu");        //add by zdn 2001-07-20

	add_door("�����ݵ�1", "�����ݵ�1", "������");
	add_door("�����ݵ�", "�����ݵ�", "������");
	add_door("�������ȹ�", "�������ȹ�", "������");

	add_door("��������ʹ����", "��������ʹ����", "������");
	add_door("���������ھ�", "���������ھ�", "������");
	add_door("��������Ӫ", "��������Ӫ", "������");
	add_door("�����ϱ�Ӫ", "�����ϱ�Ӫ", "������");
	add_door("��������Ӫ", "��������Ӫ", "������");
	add_door("��������Ӫ", "��������Ӫ", "������");
	add_door("�������", "�������", "������");
	add_door("��������", "��������", "������");
//	add_door("������У��", "������У��", "������");
	add_door("�����ĳ�", "�����ĳ�", "������");
	add_door("������������", "������������", "������");
	add_door("��������������", "��������������", "������");
	add_door("���������", "���������", "������");
	add_door("������ջ", "������ջ", "������");
	add_door("�������1", "�������1", "������");
	add_door("�������2", "�������2", "������");
	add_door("��������¥", "��������¥", "������");
	add_door("����ľ����", "����ľ����", "������");
	add_door("�������޷�", "�������޷�", "������");
	add_door("����Ǯׯ", "����Ǯׯ", "������");
	add_door("�������", "�������", "������");
	add_door("����������", "����������", "������");
	add_door("����ѧ��", "����ѧ��", "������");
	add_door("����ҩ��", "����ҩ��", "������");
	add_door("����������", "����������", "������");
	set("no_cast",  1);
};


ROOM_END;
