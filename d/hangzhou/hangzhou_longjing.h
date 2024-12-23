//longjing.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_longjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_girldizi");      //add by zdn 2001-07-14


	add_door("����ɽ·5", "����ɽ·5", "��������");

	set("long","ֻ����(jing)ˮ���ɼ��׶��������쳣������ԭ������������˵�˾��뺣��ͨ�����бض������������꣬���������������ն�������ʫ������ɽ��ˮ��ѣ������������̶�������Խ��в��ҡ����ϱ�ش�·��  ������(Mengmian ren)" );
	
	set("resource/water", 1);

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
