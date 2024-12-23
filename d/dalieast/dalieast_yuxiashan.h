//yuxiashan.h

//Sample for room: �������ϼɽ
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_yuxiashan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ϼɽ");

	//add npcs into the room
	add_npc("pub_youke2");

	CBox * box = Add_Box();
	if(!random(5))
		box->add_object("wangqing_shi", 1);	//put 100 coind into box
	else
	{
		box->add_object("sword_3",1);
	}
	box->set_name("ʯ��", "hole");
	box->Locked("���", 10000);

	
	add_door("��������ƺ���", "��������ƺ���", "�������ϼɽ");

	set("long", "��ϼɽ�������ƺ���ɽ�����㣬��������������ͺ���ɽɫ���޲�Ϊ֮�㵹��������ʫԻ����ϼ���������������ƺ�ˮ�����⣬���캬�����ϴ䣬Զɽ�ͱ�Ħ��ԣ�ˮ��ɽɫ���ӳ�� �������Ʊ��쾻��" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
