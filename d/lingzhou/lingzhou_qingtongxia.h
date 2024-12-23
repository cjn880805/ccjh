//qingtongxia.h

//Sample for room: ������ͭϿ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_qingtongxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ͭϿ");
	
	add_npc("pub_mazei");     //add by zdn 2001-07-14
	add_npc("gumu_yangguo");

	add_door("����С��", "����С��", "������ͭϿ");
	add_door("������ɳ��", "������ɳ��", "������ͭϿ");

	set("long", "�����ǻƺӺ������ȶ������׼�����ͭϿ���ƺ�һ·���ʵ���������ĺ���һ���ӱ�խ���������ͱ���һ���������˽�����Ը�ֿ����ƺ�ȴ�󲻶��µĺ��Ӵ���Ӳ�����������ˮ��һ���ӱ�������������������죬ˮ��¡¡��");  
	
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
