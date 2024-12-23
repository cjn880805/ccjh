//qianfoan.h

//Sample for room:  ����ǧ����
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CREMei_qianfoan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǧ����");

	add_npc("emei_daoming");
				
	add_door("���Ҿ�ʮ�ŵ���1", "���Ҿ�ʮ�ŵ���1", "����ǧ����");
	add_door("���Һ�����ջ��", "���Һ�����ջ��", "����ǧ����");

	set("long","�˴��Ǻ鴻ƺǧ���֡�ɽ��Сƺ�ӣ�������͵��ϣ��廷�뻤�����������ᰣ�Ϫ���ᶣ��ƺ�Ϲ�ľ���裬ͤͤ��ǣ�ɽ����͸������Ʈ�Σ���Ϊ�ľ��������˴��������������������������ɣ���ɽ��������Ϊ������ν��ɽ�б����꣬�մ�ʪ���¡����������Ϊ��۵ġ��鴻���꡹���˴��������ģ��������죬����������;�����ǡ���ʮ�ŵ��ա������¾�������ջ����������");

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
