//zhongnan.h

//Sample for room  ����ɽ��
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRZhongNancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��");

	add_npc("pub_youngwoman");
	add_npc("pub_jianke");        //2001-07-10  zdn add

	add_door("����ɽ��ٵ�", "����ɽ��ٵ�", "����");

	set  ("long","����ɽ�ֳ�̫��ɽ���೤���ǰ�ʮ������С����������������֮˵���ݴ���������ɽ�н�����������ٵ���Խ����ɽ�ڣ�����������ƣ�����ȴû��һ��·������ɽ���������������Ĵ��������ǰ����ԭ��");
};


ROOM_END;
