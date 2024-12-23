//port.h

//Sample for room: ���˶�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_port);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���˶�");
	
	add_npc("wanjie_fuer");        //add by zdn 2001-07-20



	add_door("��ٹȽ���С·3", "��ٹȽ���С·3", "��ٹ����˶�");
	add_door("��ٹ�������", "��ٹ�������", "��ٹ����˶�");

	set("long","�����ǰ�����׽���һ���ɿڣ�����������ڴ�����һ�������ţ����Ǳ㲻���ٳ˴������ˡ��ű�ʯ����������ؿ����������֡����˶ɡ���");
    
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
