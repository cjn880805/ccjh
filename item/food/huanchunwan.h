//huanchunwan.h ������

FOOD_BEGIN(CIhuanchunwan);

virtual void create(int nFlag = 0)		
{
	set_name( "������");	
	set_weight(700);
	set("unit", "��");
	set("long", "����һ�ű��̵�ҩ��,�������һ��С�֣���ϸһ����ԭ��д���ǡ�Τ�������쵤ҩ��ֻ��һ�ң��мٰ�������");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("per")<38)
	{
		me->add("per", 1);
		message_vision("$HIR$N����һ�Ż�������ͻȻ�е�һ�ɵ������������Ĳ�������ɫ����ת�ף��ɰ�ת�졣\n���в������Ե��⡰��Τ���������ջ��治��!\n$N�����������ˣ�", me);
	}
	destruct(this);
	return 1;

}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



