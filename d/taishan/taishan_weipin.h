//weipin.h

//Sample for room: ̩ɽΧ��ɽ
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_weipin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽΧ��ɽ");

	set("monster_chance", 40);

	add_door("̩ɽ���", "̩ɽ���", "̩ɽΧ��ɽ");
	add_door("̩ɽ��ϼ��", "̩ɽ��ϼ��", "̩ɽΧ��ɽ");

	set("long","������̩ɽ������һ��ɽ�塣ɽ�Ķ�����һ����ͷ�£�����״����һͷ�����������бܷ��£����ϴ��ؿ��š����¸ԡ����������档�������б���̳�������������ߣ���ɵ����ŷ�̩ɽ֮���ϼԪ���ı�ϼ����");
	

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"tianjie",
		"east" : __DIR__"bixia",
	]));
*****************************************************/
};

FIELD_END;
