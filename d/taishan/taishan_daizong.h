//daizong.h

//Sample for room: ̩ɽ��ڷ�
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_daizong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ��ڷ�");

	set("monster_chance", 40);

	add_door("̩ɽ�׺�Ȫ", "̩ɽ�׺�Ȫ", "̩ɽ��ڷ�");
	add_door("̩ɽɽ��", "̩ɽɽ��", "̩ɽ��ڷ�");

	set("long","λ��̩���س��Ա�Լһ��˴��ǵ�̩ɽ����ڡ��ഫ�����ϼԪ����������ϷŪ������Ͷ���廨Ь�Զ�̩ɽ�ؽ磬�����ϼԪ��ֻ�ܰ��廨Ь��ɽ�������˴����Ӵ�̩ɽ���Դ�Ϊ��㡣");

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"baihe",
		"south"   : __DIR__"taishanjiao",
		"west"    : "/d/huanghe/huanghe5",
	]));
	set("objects", ([
		"/quest/shan" :1,
	]));
*****************************************************/
};


FIELD_END;
