//wanxingan.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_wanxingan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("emei_jia");	

	add_door("���ҽ�����", "���ҽ�����", "����������");
	add_door("���ҽ�", "���ҽ�", "����������");

	set("long","̫��ƺ�������ǹ�����ʦ�����ġ�������ɽ����ɯ须��������źϳ�һ�䣬Ҷ�Ӱ��ڻ��⣬��������������׶�ʢ��֮�����������Ժ�֮�߹�Ʒ�ʡ��ɴ������ϱ����𶥣����������");

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
