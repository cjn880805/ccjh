//jiaxingcity.h

//Sample for room:  ���˳�
//coded by Fisho
//data: 2000-11-4


RESIDENT_BEGIN(CRjiaxingcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���˳�");

	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_kid");
	add_npc("pub_thief");

	set("resident", "����");


	add_door("��������", "��������", "���˳�");
	add_door("�����Ϻ�", "�����Ϻ�", "���˳�");	

	add_door("������ǹ��", "������ǹ��", "���˳�");
	add_door("��������¥", "��������¥", "���˳�");


/********************************************************
	set("long", @LONG
�����ǽ������Ǽ��ˡ��Ƕ��Ƿ羰�续���Ϻ����Ǳ�������������¥��
����ȫ������֮һ���𴦻��ͽ����߹־���������ԼѰ������֮�󡣲�֪
��ʲôԭ���������Ǩ�������ˡ�
LONG );
	set("exits", ([
                "west" : __DIR__"qzroad2",
                "east" : __DIR__"nanhu",
		"south" : __DIR__"jxnanmen",
	]));
****************************************************************/
};


RESIDENT_END;
