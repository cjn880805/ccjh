//gaoshengchaguan.h

//Sample for room: �������
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_gaoshengchaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");

	//add npcs into the room
	//add_npc("guanfuzi");
	add_npc("pub_lincong");
	
	add_door("�����ʳ�", "�����ʳ�", "�����������");

	set("long", "��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ������Ǹ������ڡ�" );
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
