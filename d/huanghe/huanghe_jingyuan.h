//jingyuan.h

//Sample for room: �ƺӾ�Զ
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_jingyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӾ�Զ");
	
	add_npc("pub_punk");    // add by zdn 2001-07-14



	add_door("�ƺӺ�ɽϿ", "�ƺӺ�ɽϿ", "�ƺӾ�Զ");
	add_door("�ƺ�ɳĮ1", "�ƺ�ɳĮ1", "�ƺӾ�Զ");

	set("long","��Զ�Ǹ�����С�ĳ��򣬻�ɳ�������ʮ��ĵط���һ���ŵ��������������ס�ˡ������������һ��ϴ�����ޣ��ۼ��˲��ٴӱ�����������Щ�����˵�ǵ����Ƴ��������ͻ�ʺ��������ͱ�ʱ���֡���Ҳ�Ǿ�Զ���������������߲�Զ���ǻƺӣ�������һ��ƬɳĮ��");
	

/*****************************************************
	set("exits", ([
		"north"     : __DIR__"hongshanxia",
		"south"     : __DIR__"shamo",
	]));
********************************************/
};


CHANGAN_END;
