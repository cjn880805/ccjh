//hcachanfang.h

//Sample for room:  ���һ���������
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcachanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ���������");

	add_npc("pub_boydizi");
	add_npc("pub_girldizi");            // add by zdn 2001-07-14

	add_door("���һ���������2", "���һ���������2", "���һ���������");
	add_door("���һ����ִ��۱���", "���һ����ִ��۱���", "���һ���������");

	set("long","������Ƕ��һ����ֵ�����������ɢ�ҵط���������ţ�ľ��ȣ��˴����Ǳ��ɵ��Ӵ�������֮������λ����ʦ̫���׼�Ů�����������붨����������������һ����ͨ����������Ϣ�ң����ߵ�����ͨ��㳡��");
    
    set("sleep_room", 1);
    set("no_fight", 1);
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
