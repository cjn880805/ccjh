//hcaeast2.h

//Sample for room:  ���һ����ֶ���2
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaeast2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ����ֶ���2");
	
	add_npc("pub_boydizi");        // add by zdn 2001-07-14

	add_door("���һ����ֶ���1", "���һ����ֶ���1", "���һ����ֶ���2");
	add_door("���һ�����ի��", "���һ�����ի��", "���һ����ֶ���2");

	set("long","�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã�����ͨ���㳡��");
    
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
