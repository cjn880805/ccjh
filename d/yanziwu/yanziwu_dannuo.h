//dannuo.h

//Sample for room: �������Ŵ��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_dannuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Ŵ��");

	add_door("����������", "����������", "�������Ŵ��");
	add_door("����������ˮ�", "����������ˮ�", "�������Ŵ��");

    set("long", "����һ�����µĴ��������ϰ��ż�����̴ľ�������������Ʋ;�һӦ��ȫ������һ���绨ľ�Ρ�ÿ��Ľ�����Һܶ��˶��ڴ��ò͡�" );
    
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
//last, register the room into ../server/RoomSetup.cpp