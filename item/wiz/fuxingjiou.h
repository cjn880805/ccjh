//fuxingjiou.h ���Ǿ�

FOOD_BEGIN(CIfuxingjiou);

virtual void create(int nFlag = 0)	
{
	set_name( "���Ǿ�");	
	set("unit", "��");
	set("long", "��ٴ͸�����Ϊ����");
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add_temp("apply/str",1);
	me->add_temp("apply/int",1);
	me->add_temp("apply/con",1);
	me->add_temp("apply/dex",1);
	message_vision( "$N����һ�����Ǿ� ��ֻ�����������У�ͻ����ǰ�ľ��硣" , me);
	destruct(this);
	return 1;
}

FOOD_END;





