//gongling.h

//Sample for room: ���ݹ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRlingzhou_lingxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

//	add_door("����������", "����������", "��������");
    //add_npc("xiaxueyi");          //add by zdn 2001-07-20


	set("long", "�������������ذ�˼������Ĺ���ذ�˼�������ʵ���Ǽ���˳��̫���������������Ϊ�����˼�����Ƴ�Ҳ�Ǽ������Ĵ󽫡������Ϊ�����Զ������ĹҲ�����������ΰ������ȥ�е��ưܡ�");  
	
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