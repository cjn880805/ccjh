//baihe.h

//Sample for room: ̩ɽ�׺�Ȫ
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_baihe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ�׺�Ȫ");

	set("monster_chance", 20);

	add_door("̩ɽ��ڷ�", "̩ɽ��ڷ�", "̩ɽ�׺�Ȫ");
	add_door("̩ɽһ����", "̩ɽһ����", "̩ɽ�׺�Ȫ");

	set("long","�ഫ��ǰ������һ���׺�Ȫ������ˮ��������Ϊ̩ɽ֮���Ȫˮ����ӿ�����ϣ������ˮ���ɺ������ų��ϴ��һ��������Ϊ������ϧ������һ����˽������С�٣�������Ȫˮ�������������ŷ�ˮ֮˵����Ȫ�۶������׺�Ȫ�Ӵ˱�ɺ��ˡ�����ֻʣ��һ�����š��׺�Ȫ�����ֵ�ʯ����Ϊ���������������ϣ�������ɽ֮·��");
	set("resource/water",1);
	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));
*****************************************************/
};


FIELD_END;
