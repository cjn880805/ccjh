//yinpiao1.h ��Ʊ
//muri 2001-11-16

ITEM_BEGIN(CIyinpiao1)

void create(int nFlag = 0)	
{
	set_name("��Ʊ", "yin piao");
	set_weight(10000);
    set("value", 150);

	set("unit", "��");	
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255,  "�������ݾ۱�ի������һ����Ʊ����ֵ%d����",query("value")*8/10);
	say(msg, me);
	SendMenu(me);
	return 1;
}


ITEM_END;
