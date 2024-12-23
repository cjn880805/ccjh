//hu.h
//��������
//2001-01-09

VENDOR_BEGIN(CNhelpnpc_jhlz);

virtual void create()
{
	set_name("��������", "jianghulangzhong");
	set("title","������");
	set("long","��������");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man5); 
	set("env/wimpy", 100);      
	
	set("max_hp", 4500);
	set("hp",  1500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("score", 80000);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed",180);
	set_skill("parry", 180);

	carry_good("jiudai", 20);
	carry_good("blackcloth", 5);
	carry_good("peanut", 5);
	carry_good("yangbian", 5);
	carry_good("baozi", 10);
	carry_good("egg", 10);
	carry_good("gao", 10);
	carry_good("gao3", 10);
	carry_good("sherou", 20);
	carry_good("tanghulu", 20);
	carry_good("turou", 20);
	carry_good("bu_shoes", 20);
	carry_good("baozi2", 20);
	carry_good("backleg", 10);
	carry_good("jitui", 10);
	carry_good("mangguo", 1);
	carry_good("yadan", 4);
	carry_good("gourou", 20);
	carry_good("zongzi", 100);
	carry_good("senggun", 20);
	carry_good("chanzhang", 5);
	carry_good("qimeigun", 5);
	carry_good("ruanjian", 10);	
	carry_good("zhujian", 20);
	carry_good("jiujiebian", 20);
	carry_good("dafu", 20);
	carry_good("changjian", 20);
	carry_good("doupeng", 20);
	carry_good("shoutao", 10);
	carry_good("tiebeixin", 10);
	set("no_talk",1);
}
int do_talk(CChar * me, char * ask = NULL)
{
	char xingbie[10];
	int myage=0;
	int mylevel=0;
	myage=me->query("age");
	mylevel=me->query("level");
	static char hua1[22][10]=
	{
		"��ʿ",
		"̫�Ҽ���",
		"������",
		"׳��",
		"����",
		"槼�",
		"���ٸ�",
		"������",
		"����",
		"����",
		"С����",
		"С��",
		"����",
		"����Ů",
		"������",
		"�߹���",
		"������",
		"δ��֪",
		"���",
		"����",
		"������",
		"����"
	};
	static char hua2[22][30]=
	{
		"��֮���ð���",
		"��˵�������ˡ���",
		"��л���㽲�ɣ�",
		"�ǳ���л��",
		"˵Ҳ�޷���",
		"˵�ɣ�˵������Ҳ��ʶ�أ�",
		"���Ѷ��˺ð���",
		"˵ѽ������ʲô��",
		"��Ҳ��Ը�⽻���Ѱ���",
		"���ѣ���Ȥ���뽲��",
		"���׶���Щʲô�˰���",
		"�������ǲ��Ǻܶడ��",
		"���������һ���ˡ�",
		"�Ǻǣ��ҵ�Ҫ��һ����",
		"���������㻹���Ƚ��ɡ�",
		"�õģ���������ʶһ���ء�",
		"Ը�����ꡣ",
		"��ֻ��·��������Ҳ�á�",
		"�ҵ��������Ϊ�˽����ѡ�",
		"˵�ɣ��һ��ס�ġ�",
		"������û�˰�æ�أ�",
		"�⻹��˵��"
	};

	static char hua3[22][60]=
	{
		"�������롣����",
		"����ֻ�ǵ�������ô���ˡ�",
		"��Щ����Щ�Ѿ��þ�û�����ˡ�",
		"�������˴󲿷ֶ������ι�����",
		"��Щ�˿�����Щ��Ҳ��������",
		"�ҵ��������̾������ܿ�����Щ���Ѿ������ˡ�",
		"����̫���ˣ���˵��һ���أ����ˣ������⼸������һ�¡�",
		"�����ڻ���һЩ�����ѣ��������ǵ������ˣ�����˭��˵˭�ɡ�",
		"�����������ǣ���˵���ҵ����ѡ�",
		"��ҲҪ��ʶЩ���Ѱ�����Щ���кܶ඼���ҵ��������ˡ�",
		"���ڸ��㽲�����Ѳ�֪��������û�У�",
		"��������ʹ��ˣ�ֻ�ܼǵ����¼����ˡ�",
		"��ʵ������Ҳ����ʶ�ö����ѣ�������������Ѿ�������ȥ�ˡ�",
		"�������β�������ʶ�ܶ����ѣ�����������һ����ʶ�����Ѻܶࡣ",
		"����Щ���Ѷ����������ģ�������������������ˡ�",
		"��Щ���ѿ�������ʱ�������������̬�Ȼ᲻һ���ġ�",
		"������Щ�˺ܹ֣��������������ǲŻ�֪����",
		"�Ҿ������˽������ѵģ��㲻��л�ҡ�",
		"��Ҳ��һЩ�����Ǵ����������ǲ�����͸¶���ǵ���ʵ������",
		"��Ҳ��һЩ������ħͷ���Ҳ���˵�����ǵ���ʵ������",
		"������֮��͸Ͽ��뿪����������ҵ���̫���ˡ�",
		"����˯�ıȽϺã���������ܶ����������"
	};

	if(!strlen(ask))
	{
		char msg1[50];
		strcpy(xingbie,me->querystr("gender"));
		if(strcmp(xingbie,"Ů��")==0)
			strcpy(msg1,"С�㣬�������ˣ���Ҫ��æ��");
		else if(strcmp(xingbie,"����")==0)
			strcpy(msg1,"С�ֵ�,�������ˣ���Ҫ��æ��");
		else
			strcpy(msg1,"С����,�������ˣ���Ҫ��æ��");
		if(!random(5))
			say("������˵������ҽ�š����Ǿ���˵���أ�����������ĸ���������",me);
		if(!random(5))
			say("��ֻ��С�����ˣ�",me);
		if(!random(5))
			say("���ڽ���������Ҫ�࣬�����Ҫ��æ�뾡�ܿ��ڣ�",me);
		if(!random(5))
			say("����һ����ϰ�ߣ���С��ֻ�β�������Ǯ��",me);
		if(!random(5))
			say("����������������֮ͽ��ϣ���㲻�ǡ�",me);
		if(!random(5))
			say("�кܶ��˶����Ҿȵģ���������Ե�������������",me);
		if(!random(5))
			say("��������������ˣ��������������ҡ�",me);
		if(!random(5))
			say("Ұ���кܶ඾�ߣ���·ҲҪС�İ���",me);
		if(!random(5))
			say("��Щ�ط��������ṥ�������ߣ��кܶ����Ѿ��ܵ������ǵ��˺���",me);
		if(!random(5))
			say("������ҩ���󣬹�ƽ������Ҳ������һ�ԡ�",me);
		if(!random(5))
			say("�����и��������Ǳ�Ѳ��ɱ�˵ģ����һ��Ǿ�������",me);
		if(!random(5))
			say("�һ��кܶ�ͬ���ڿ�ҩ�̣���һ�����������ǵġ�",me);
		if(!random(5))
			say("��Ϊû�й̶���������ֻ�õ�������Ϊ����",me);
		if(!random(5))
			say("���ϲ�Ҫ��̫��Ĳ���ܶ�����������ɫ��",me);
		if(!random(5))
			say("�Ұ�Ǯ����Ǯׯ���ˣ�����ֻ����ЩҩƷ�ˡ�",me);
		if(!random(5))
			say("��������Ұ��ɹ�Щ��ҩ����㱻����ҧ�ˡ�",me);
		if(!random(5))
			say("�����̫���ˣ���ǲ�������˭�ˡ�",me);
		if(!random(5))
			say("�������ҵ��˺ܶ࣬���ۡ�",me);
		if(me->query("max_hp")!=me->query("eff_hp")&&myage==14)
	   {
			say(msg1,me);
			AddMenuItem("�õģ���л�ˣ�", "a", me);
			AddMenuItem("���á�", "b", me);
			SendMenu(me);
			return 1;

	   }
	   else
	   {
		   if(me->query_temp("talk/times")>2)
			   return 0;
			say("�ò��ð�����ܼ������Ѱ���",me);
			AddMenuItem(hua2[random(22)], "00", me);
			SendMenu(me);
			return 1;
	   }
//       AddMenuItem("", "2", me);
	}
	if(strcmp(ask,"a")==0)
	{
		message_vision("��������ι$N����һ��ҩ��,Ȼ����ϥ���£�˫������$N�ı��ġ�", me);
		me->set("eff_hp",  me->query("max_hp"));
		message_vision("��Լ���˲���һ�Ѳ��ʱ�ݣ���������������վ��������",me);
		message_vision("�������ж�$N˵������������Ѿ�ȫ����,����������", me);
		say("���ˣ���˯һ���ɣ�",me);
	}
	else if(strcmp(ask,"b")==0)
	{
		message_vision("�������ж�$N˵�������ǲ���С���ҵ�ҽ�������������¡�", me);
		message_vision("��������ι$N����һ��ҩ��,Ȼ����ϥ���£�˫������$N�ı��ġ�", me);
		me->set("eff_hp",  me->query("max_hp"));
		message_vision("��Լ���˲���һ�Ѳ��ʱ�ݣ���������������վ��������",me);
		message_vision("�������ж�$N˵������������Ѿ�ȫ����,����������", me);
		say("���ˣ���ס�´�����Ҫ���ƲŶ԰���",me);
	}
	else if(strcmp(ask,"00")==0)
	{
		say(hua3[random(22)],me);
		me->set_temp("talk/times",me->query_temp("talk/times")+1);
		if(!random(4))
			AddMenuItem(hua1[0], "0", me);
		if(!random(4))
			AddMenuItem(hua1[1], "1", me);
		if(!random(4))
			AddMenuItem(hua1[2], "2", me);
		if(!random(4))
			AddMenuItem(hua1[3], "3", me);
		if(!random(4))
			AddMenuItem(hua1[4], "4", me);
		if(!random(4))
			AddMenuItem(hua1[5], "5", me);
		if(!random(4))
			AddMenuItem(hua1[6], "6", me);
		if(!random(4))
			AddMenuItem(hua1[7], "7", me);
		if(!random(4))
			AddMenuItem(hua1[8], "8", me);
		if(!random(4))
			AddMenuItem(hua1[9], "9", me);
		if(!random(4))
			AddMenuItem(hua1[10], "10", me);
		AddMenuItem("����", "hong", me);
		if(!random(4))
			AddMenuItem(hua1[11], "11", me);
		if(!random(4))
			AddMenuItem(hua1[12], "12", me);
		if(!random(4))
			AddMenuItem(hua1[13], "13", me);
		if(!random(4))
			AddMenuItem(hua1[14], "14", me);
		if(!random(4))
			AddMenuItem(hua1[15], "15", me);
		if(!random(4))
			AddMenuItem(hua1[16], "16", me);
		if(!random(4))
			AddMenuItem(hua1[17], "17", me);
		if(!random(4))
			AddMenuItem(hua1[18], "18", me);
		if(!random(4))
			AddMenuItem(hua1[19], "19", me);
		if(!random(4))
			AddMenuItem(hua1[20], "20", me);
		if(!random(4))
			AddMenuItem(hua1[21], "21", me);

	}
	else if(strcmp(ask,"hong")==0)
	{
		say("������Ѿ��������ˣ��������ʲô���⣬�㻹���Լ�����������һ�����æ�ġ�",me);
	}
	else if(strcmp(ask,"0")==0)
	{
		say("��˵���������������־�������װ�����ܣ����������뽭���Ӵ�������ʶ������������û��ס������",me);
	}
	else if(strcmp(ask,"1")==0)
	{
		say("��ԭ���䵱���£���ʿ�����о��������أ�ͨ�����Ŷݼף���˵ľż�˺�ֽ�˾�����������",me);
		say("�þ�û�������ˣ������ݽ������ţ�������ַ�����һ�����ܻ����ˣ���������δ�ڽ����ϳ��֡�",me);
		say("С�ֵ������Ե�õ��Ļ��������ô��Ҳ�����۽硣",me);
	}
	else if(strcmp(ask,"2")==0)
	{
		say("����������������ɰ��Ľ���Ů���ˣ������뻨��Ϊ�飬Ҳ�˽�һЩ������ԭ���ʹ�÷���",me);
	}
	else if(strcmp(ask,"3")==0)
	{
		say("���ڳ���Ľ������������������ƾ����У��ֻ���˺ɱ�����Դ�Ҷ�Ҫ���ϵ���ļ���ˣ��Ҽ����ܶ�׳�������Ǵ󶼺�������",me);
		say("�Ҽ�����׳�����ڴ󲿷��Ѳμ��˸��Ÿ����ˣ�Ҳ��Ϊ���������ġ��㿴������Ѳ�ǵ��α��У�˵��������ʶ���ء�",me);
	}
	else if(strcmp(ask,"4")==0)
	{
		say("���������кܶ����ɶ�����ͨ��������������й¶������̫���˰ɣ���ҲҪС��һ�㣬������ͨ������ǳԲ����ġ�",me);
	}
	else if(strcmp(ask,"5")==0)
	{
		say("��Ƥ��߾��������ģ���Ҳ��һЩ᪻�֮������ʵ���ǳ�˹֣���֪��ô���������ڵ������ˡ���ҪС�ģ�˵������������������ȥ��ҡײƭ�ˡ�",me);
	}
	else if(strcmp(ask,"6")==0)
	{
		say("��ԭ��Ҳ���ҵ����ѣ�����������ҥ˵�����Ͷ���˵й���Ҳ��֪�������Ǽ١�",me);
	}
	else if(strcmp(ask,"7")==0)
	{
		say("������ܵõ�����һ��ָ��������Ĳ���һ������а�����",me);
	}
	else if(strcmp(ask,"8")==0)
	{
		say("С�����Ľ������Ҷ���ܹ�����ƭ�����Ǻ�����֪���ġ�",me);
	}
	else if(strcmp(ask,"9")==0)
	{
		say("�������ղ��кܶ�Źֵı�������ÿ�μ������������ʹ�ò�ͬ���������������������ִ����������д裬��ĺܹ֡�",me);
	}
	else if(strcmp(ask,"10")==0)
	{
		say("�ޣ��������ᣬ�������ҵ����ӡ�ֻ�ǽ����϶�һ��ıʿ����ƣ�������������Ļ������ܻ����ܶ�æ��",me);
	}
	else if(strcmp(ask,"11")==0)
	{
		say("��С���ݳ���Ϸ����ÿ���ؿ��ģ��ǳ����ʣ���ʱ��Ҳ�ῴ�������ڽ�ͷ���գ����ںܶࡣ",me);
	}
	else if(strcmp(ask,"12")==0)
	{
		say("���ѵ�û��˵�������Ĵ����֮�װ����������һ���˶�֪���İ���",me);
	}
	else if(strcmp(ask,"13")==0)
	{
		say("�������û�������������һ���������ˡ��������������������˺ܶࡣ",me);
	}
	else if(strcmp(ask,"14")==0)
	{
		say("˵�������ǲ������Ǵΰ������ˣ��������蹻�ˣ�����Ҳ��������ˡ��´α�������ǰ��������",me);
	}
	else if(strcmp(ask,"15")==0)
	{
		say("������ү���߹��������������ү�����ж����ҲŲ���������أ����ˣ�����������֪���ˡ�",me);
	}
	else if(strcmp(ask,"16")==0)
	{
		say("�ⲻ֪���ǲ�����������������Ҷ���ô������ÿ�����˵Ҫ������ȡ����Ī�����",me);
	}
	else if(strcmp(ask,"17")==0)
	{
		say("�������������˳ơ�ǰ֪����꣬���������ꡱ����ʮ��ǰ����˵�������У�����������������й¶�����һ��Ҫ����Ե�˲��С�",me);
	}
	else if(strcmp(ask,"18")==0)
	{
		say("�Ҳ��Ǻ��˽����������󾭳���ʲô���顣",me);
	}
	else if(strcmp(ask,"19")==0)
	{
		say("�ڽ�����һ�������ߺܲ����ף�û���������ǲ��еģ�����һЩ�򵥵Ļ������⣬�����������̣�������֪�޲��ԣ����޲�����",me);
	}
	else if(strcmp(ask,"20")==0)
	{
		say("��һ��ʮ�������������ԶһЩ���Ǻá����Ѳ���",me);
	}
	else if(strcmp(ask,"21")==0)
	{
		say("����һ��������У����������֪���ˡ�",me);
	}
	else
	{
		return 0;
	}
		
	SendMenu(me);
	return 1;
	
}

virtual int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s����ô�Ǵ����Ķ����أ�",query_respect(me) ));
	return 0;
}
/*
virtual void die()
{
	revive(1);
//	message_vision("$N��������������˿�����", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);

}
*/
VENDOR_END;