//yinpiao.h ��Ʊ
//muri 2001-11-16

ITEM_BEGIN(CIyinpiao)

void create(int nFlag = 0)	
{
	set_name("��Ʊ", "yin piao");
	set_weight(10);
    set("value", 70000);

	char msg[255];
	set("long",snprintf(msg, 255,  "�������ݾ۱�ի������һ����Ʊ����ֵ%d����",query("value")*8/10));
	set("unit", "��");	
}


ITEM_END;
