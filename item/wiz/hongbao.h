//hongbao.h ѹ����
//muri 2002-2-5

ITEM_BEGIN(CIhongbao)

void create(int nFlag = 0)	
{
	set_name("ѹ����", "hong bao");
	set_weight(10);
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

	set("long", "���ǽ�������˾���͸�������������ʱ����Ȼ���߷ܶ��������ǵ�ѹ������");
	set("unit", "��");	

	set("open_msg", "С�������˺���˺�����");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	char msg[255];

	message_vision(snprintf(msg, 255, "$HIY$N%s���Ӻ���е�����һ�ѵĽ�ң������̵���������...", querystr("open_msg")), me);
	tell_object(me,snprintf(msg, 255, "1����ҡ�2����ҡ�3����ҡ�4�����......") );
	tell_object(me,snprintf(msg, 255, "108����ҡ�118����ҡ�128����ҡ�138�����......"));
	tell_object(me,snprintf(msg, 255, "1088����ҡ�1188����ҡ�1288����ҡ�1388�����......"));
	tell_object(me,snprintf(msg, 255, "10888����ҡ�11888����ҡ�12888����ҡ�13888�����......"));
	tell_object(me,snprintf(msg, 255, "$HIY��������������ǰ����ѽ�ң�����ĵ��˵�ͷ���ܹ��յ���16888����ҵ�һ�����"));
	CMoney::Pay_Player(me, 16888);
	destruct(this);
	message_vision(snprintf(msg, 255, "$HIY$N���˶�������������滹��һЩ��������Ķ�����˳�־�ץ�˳�����"),  me);
	load_item("fuxingjiou")->move(me);
	load_item("shouxingtao")->move(me);
	load_item("lvxingguo")->move(me);
	tell_object(me,snprintf(msg, 255, "������һ�����Ǿơ�һ��»�ǹ���һ�������ҡ�"));
	return 1;

}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;




