//wudafu.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_wudafu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");

	set("monster_chance", 30);
	set("monster_type", 2);

	add_door("̩ɽ������", "̩ɽ������", "̩ɽ������");
	add_door("̩ɽ����", "̩ɽ����", "̩ɽ������");

	set("long","�ഫ������ʼ����̩ɽ�����������������������͵������������±��꣬���û���š���ˣ����ͷ�����������Ϊ�����򡹡�������֪����������һ��޴�ķ���ʯ���������������ˡ����������Բ��������������ڲ�Զ������һ������ƺ����˵������ʼ�ʵ�����ʵ�λ�á�����������ɽ���߱�ᵽ��ʮ���̵���ڡ�");
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"longmen",
		"southdown" : __DIR__"ertian",
	]));
*****************************************************/
};


FIELD_END;
