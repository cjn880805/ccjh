//exam1.h �����Ծ�
//muri 2001-11-16

ITEM_BEGIN(CIexam1)

void create(int nFlag = 0)	
{

	set_name("�����Ծ�", "hong bao");
	set_weight(10);
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

	set("long", "�����Ծ�");
	set("unit", "��");	
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	static struct{
		char title[255];									//��Ŀ
		char key1[255],key2[255],key3[255],key4[255];		//��
		int key;											//��ȷ��
	}exam[8] = {
		{"��ӹ�ĳ�������?","1924-2-1","1924-4-1","1925-2-1","1925-4-1",1,},
		{"�����Ȼ�����Ƶġ�������족һ�г�����������µڼ���?","34","36","43","33",1,},
		{"ľ���Ƕ��´����ý��ĵڼ����׶�?","4","5","6","7",1,},
		{"����ù���˵�˼�������Ӣ�ۡ�?","5","6","7","8",1,},
		{"�����������Ǽ��أ������������˶�����?","277","276","271","278",1,},
		{"�����������ж����ɾ��ֱ����ж������?","12","13","14","15",1,},
		{"���������������ػ���Ů�Ӿ�лѷʱ���˼������?","8","9","7","6",1,},
		{"�䵱��ȭ���ж���ʽ?","32","33","34","35",1,},
	};
	int idx ;
	idx= random(8)+1;
	say("׼���ã�����Ҫ��ʼ�ˣ�Ҫע����;���ǲ����˳���Ҳ�����Ի�ͷ�ġ�", me);
	AddMenuItem(exam[idx].title, "1", me);
	SendMenu(me);
	AddMenuItem(exam[idx].key1, "11", me);
	AddMenuItem(exam[idx].key2, "12", me);
	AddMenuItem(exam[idx].key3, "13", me);
	AddMenuItem(exam[idx].key4, "14", me);
	SendMenu(me);
	return 1;
}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;




