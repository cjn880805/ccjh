//dalisouth.h

//Sample for room:  ���������
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
RESIDENT_BEGIN(CRDaLisouthcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");


	add_door("�������", "�������", "���������");
	add_door("������ּ�С��2", "������ּ�С��2", "���������");
	add_door("�����˫����", "�����˫����", "���������");

	set("long","�˼��Ǵ����������ǵ����ţ������ʵ��������ǣ���گ�ڳ���������������������Ķ��ϵġ�������������Դ˳�Ϊ������ǽ��ʯ������ݳɣ��߶����壬�����ɡ��������������������ľ�ʿ�ɴ����۾��۲����������������ˣ�ż�����ʼ����μ����ɷ��ӡ�");
	
};

RESIDENT_END;
