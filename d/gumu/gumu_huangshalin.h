//huangshalin.h

//Sample for room: ��Ĺ��ɳ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_huangshalin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ��ɳ��");

	add_npc("pub3_huangyishizhe");   //add by zdn 2001-07-13 
	add_npc("pub_shenmike");

	add_door("��ĹĹ��", "��ĹĹ��", "��Ĺ��ɳ��");

	set("long","�˴�λ�����ɽ������ֻ��Զ������ԭ�ϣ�������һ���ɻ�ɳ�ѻ����ɵ�ɽ�룬����Ϊ���ء��ݵ�����˵���������̳���һλ����½���ɵ��ˣ��÷���ǲ��һ�ɻ�ɳ���ɡ�������һƬ���֡�" );
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
