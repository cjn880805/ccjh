//exam1.h 武侠试卷
//muri 2001-11-16

ITEM_BEGIN(CIexam1)

void create(int nFlag = 0)	
{

	set_name("武侠试卷", "hong bao");
	set_weight(10);
    set("no_give", "好大方的人呀，不如给我吧！");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","这么珍贵的东西你也扔？！");

	set("long", "武侠试卷");
	set("unit", "张");	
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	static struct{
		char title[255];									//题目
		char key1[255],key2[255],key3[255],key4[255];		//答案
		int key;											//正确答案
	}exam[8] = {
		{"金庸的出生日期?","1924-2-1","1924-4-1","1925-2-1","1925-4-1",1,},
		{"杨过黯然销魂掌的“杞人忧天”一招出现在神雕侠侣第几回?","34","36","43","33",1,},
		{"木剑是独孤大侠用剑的第几个阶段?","4","5","6","7",1,},
		{"杨过让郭襄说了几个“大英雄”?","5","6","7","8",1,},
		{"据倚天屠龙记记载，明朝共存在了多少年?","277","276","271","278",1,},
		{"倚天屠龙记中峨嵋派静字辈共有多少尼姑?","12","13","14","15",1,},
		{"倚天屠龙记中神秘黄衫女子救谢逊时带了几个随从?","8","9","7","6",1,},
		{"武当长拳共有多少式?","32","33","34","35",1,},
	};
	int idx ;
	idx= random(8)+1;
	say("准备好，考试要开始了，要注意中途可是不能退出，也不可以回头的。", me);
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




