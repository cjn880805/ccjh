//slide.h

//Sample for room: ɽ��
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_slide);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��");
	
	add_npc("wanjie_gan");        //add by zdn 2001-07-20



	add_door("��ٹ����׽���", "��ٹ����׽���", "��ٹ�ɽ��");
	add_door("��ٹ�ɽ·1", "��ٹ�ɽ·1", "��ٹ�ɽ��");

	set("long","ɽ��֮������һЩ��֪�����Ӳݣ��Լ����������ֲ����Ĺ�ľ�ԣ���������д���������Ұ����·�����Ŀ��ţ�ż���м�ֻ����������ȥ��");
    
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
