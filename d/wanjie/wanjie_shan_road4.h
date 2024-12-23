//shan_road4.h

//Sample for room: ɽ·4
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_shan_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·4");
	
	add_npc("pub_punk");          //add by zdn 2001-07-16


	add_door("��ٹ�ɽ·3", "��ٹ�ɽ·3", "��ٹ�ɽ·4");
	add_door("��ٹȴ�ɭ��", "��ٹȴ�ɭ��", "��ٹ�ɽ·4");

	set("long","����һ��ɽ��С·������ɽ�������������ľ�����紵��������ɳɳ��������·����������Ӳݣ�������������������߶�����������ԶԶ�ɼ���ѹѹһƬ��ɭ�֡�");
    
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
