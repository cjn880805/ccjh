//xiaowu2.h

//Sample for room: ������С��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_xiaowu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С��");

	//add npcs into the room
//	add_npc("pub_sun");
	add_npc("pub_lady3");                  //add by zdn 2001-07-01--14

	CBox * box = Add_Box();
	box->add_object("ping", 1);	
	box->set_name( "����");	
	
	add_door("��Ĺ����", "��Ĺ����", "��Ĺ������С��");

	set("long","������Զ��������һ��С�ݣ���ʰ���������һ����Ⱦ�����������ͨ�˼�һ�㣬��ľ�����Σ�ϸ�ŵı���������Ĵ󴲡����ֱ���󲻵�������Ĺ�Ĺ֮�л�����Ȱ��衣" );

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
