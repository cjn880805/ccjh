//bozang.h

//Sample for room: ̩ɽ������
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_bozang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ������");

	set("monster_chance", 40);
	add_door("̩ɽ��ϼ��", "̩ɽ��ϼ��", "̩ɽ������");

	set("long","������̩ɽ��һ����ʤ��������һ��״��ʨ�ӵľ�ʯ����Ϊʨ���¡�������Ļ���Ҫ���ڶ�����Ķ�����Ҳ���������ǹŴ������ĵط���������һ�������ڵļ�̩ɽ����");
	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"bixia",
	]));
*****************************************************/
};


FIELD_END;
