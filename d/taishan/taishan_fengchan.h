//fengchan.h

//Sample for room: ̩ɽ����̨
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_fengchan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ����̨");
	
	add_npc("taishan_tianbai");        //add by zdn 2001-07-20



	add_door("̩ɽ��ʶ�", "̩ɽ��ʶ�", "̩ɽ����̨");

	set("long","�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ��������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨�ϰڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬���飺�����е� �ĸ����֡� �������Ҹ���������λ������ʿ�����߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�����");
	

/*****************************************************
	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));
	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));
*****************************************************/
};


ROOM_END;
