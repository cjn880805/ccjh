//yinpiao.h ��Ʊ
//muri 2004-10-23

ITEM_BEGIN(CIcaipiao)

void create(int nFlag = 0)	
{
	set_name("��Ʊ", "cai piao");
	set_weight(100);
    set("value", 10);

	char msg[255];
	if(query("number"))
		set("long",snprintf(msg, 255,  "�������ݾ۱�ի������һ�Ų�Ʊ�����Ϊ��%d��",query("number")));
	else
		set("long", "�������ݾ۱�ի������һ�Ź��ڲ�Ʊ��");
	set("unit", "��");	
}


ITEM_END;
