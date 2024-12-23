#include "stdafx.h"

#include "Globle.h"
#include "Char.h"

const char * query_rank(CChar * ob)
{
	CMapping * fam;
	int budd = 0;

	if ( (fam = ob->querymap("family")) && EQUALSTR(fam->querystr("family_name"), "少林派" ) )
		budd = ob->query_skill("buddhism", 1);

	LONG shen = ob->query("repute");
	string cla = ob->querystr("class");
	LONG score = ob->query("trade/score");

	if(EQUALSTR(ob->querystr("gender"), "女性"))
	{
		if(ob->query_condition("prostitute"))
			return "【 艺　妓 】";
		
		if(ob->query("威望")>=100)
			return "【绝世佳人】";

		if(score > 500)
		{
			if(score < 2000)
				return "【 小  贩 】";
			else if(score < 15000)
				return "【 商  人 】";
			else if(score < 50000)
				return "【大 商 人】";
			else 
				return "【红顶商人】";			
		}
		
		if(cla == "bonze")
			return "【 尼  姑 】";
		else if(cla == "taoist")	
			return "【 女  冠 】";
		else if(cla == "bandit")
			return "【 女飞贼 】";
		else if(cla == "dancer")
			return "【 舞  姬 】";
		else if(cla == "scholar")
			return "【 才  女 】";
		else if(cla == "officer")
			return "【 女  官 】";
		else if(cla == "fighter")
			return "【 女武者 】";
		else if(cla == "swordsman")
			return "【 女剑士 】";
		else if(cla == "alchemist")
			return "【 女方士 】";
		else if(cla == "shaman")
			return "【 女巫医 】";
		else if(cla == "beggar")
			return "【女叫化子】";			
		else 
		{
			if( (ob->query("pks") > 150) )
				return "【女杀人魔】";
			else if (shen >= 500000)
				return "【旷世女侠】";
			else if (shen >= 50000)
				return "【 女大侠 】";
			else if (shen >= 5000)
				return "【 女  侠 】";
			else if (shen >= 500)
				return "【 女少侠 】";
			else if (shen <= -500000)
				return "【 女魔王 】";
			else if (shen <= -50000)
				return "【 女大魔 】";
			else if (shen <= -5000)
				return "【 女  魔 】";
			else if (shen <= -500)
				return "【 女少魔 】";
			else if( ob->query("thief") > ob->query_skill("stealing") + 10 ) 
				return "【女 惯 窃】";
			else
				return "【 平  民 】";
		}
	}
	else
	{
		if(ob->query("威望")>100)
			return "【盖世英豪】";

		if(score > 500)
		{
			if(score < 2000)
				return "【 小  贩 】";
			else if(score < 15000)
				return "【 商  人 】";
			else if(score < 50000)
				return "【大 商 人】";
			else 
				return "【红顶商人】";			
		}

		if(cla == "bonze")
		{
			if (budd >= 150)
				return "【 长  老 】";
			else if (budd >= 120)
				return "【 圣  僧 】";
			else if (budd >= 90)
				return "【 罗  汉 】";
			else if (budd >= 60)
				return "【 尊  者 】";
			else if (budd >= 40)
				return "【 禅  师 】";
			else if (budd >= 30)
				return "【 比  丘 】";
			else
				return "【 僧  人 】";
		}
		else if(cla == "taoist")
			return "【 道  士 】";
		else if(cla == "bandit")
			return "【 盗  贼 】";
		else if(cla == "scholar")
			return "【 书  生 】";
		else if(cla == "officer")
			return "【 官  差 】";
		else if(cla == "fighter")
			return "【 武  者 】";
		else if(cla == "swordsman")
			return "【 剑  士 】";
		else if(cla == "alchemist")
			return "【 方  士 】";
		else if(cla == "shaman")
			return "【 巫  医 】";
		else if(cla == "beggar")
			return "【 叫化子 】";
		else
		{
			if( ob->query("pks") > 150 )
				return "【 杀人魔 】";
			else if (shen >= 500000)
				return "【旷世大侠】";
			else if (shen >= 50000)
				return "【 大  侠 】";
			else if (shen >= 5000)
				return "【 侠  客 】";
			else if (shen >= 500)
				return "【 少  侠 】";
			else if (shen <= -500000)
				return "【 魔  王 】";
			else if (shen <= -50000)
				return "【 大  魔 】";
			else if (shen <= -5000)
				return "【 魔  头 】";
			else if (shen <= -500)
				return "【 少  魔 】";
			else if( ob->query("thief") > ob->query_skill("stealing") + 10 ) 
				return "【 惯  窃 】";
			else
				return "【 平  民 】";
		}
	}
}

const char * query_respect(CChar * ob)
{
	int age;
	const char * str;

	str = ob->querystr("rank_info/respect");
	if(str[0]) return str;

	age = ob->query("age");
	string cla = ob->querystr("class");

	if( EQUALSTR(ob->querystr("gender"), "女性"))
	{
		if(cla == "bonze")
		{
			if( age < 18 ) return "小师太";
			else return "师太";
		}
		else if(cla == "taoist")
		{
			if( age < 18 ) return "小仙姑";
			else return "仙姑";
		}
		else 
		{
			if( age < 18 ) return "小姑娘";
			else if( age < 50 ) return "姑娘";
			else return "婆婆";
		}
	}
	else 
	{
		if(cla == "bonze")
		{
			if( age < 18 ) return "小师父";
			else return "大师";
		}
		else if(cla == "taoist")
		{
			if( age < 18 ) return "道兄";
			else return "道长";
		}
		else if(cla == "fighter" || cla == "swordsman")
		{
			if( age < 18 ) return "小老弟";
			else if( age < 50 ) return "壮士";
			else return "老前辈";
		}
		else
		{
			if( age < 20 ) return "小兄弟";
			else if( age < 50 ) return "壮士";
			else return "老爷子";
		}
	}
}

const char * query_rude(CChar * ob)
{
	int age;
	string cla;
	const char * str;

	str = ob->querystr("rank_info/rude");
	if(str[0]) return str;

	age = ob->query("age");
	cla = ob->querystr("class");
	
	if(EQUALSTR(ob->querystr("gender"), "女性"))
	{
		if(cla == "bonze")
			return "贼尼";
		else if(cla == "taoist")
			return "妖女";
		else
		{
			if( age < 30 ) return "小贱人";
			else return "死老太婆";
		}
	}
	else
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "死秃驴";
			else return "老秃驴";
		}
		else if(cla == "taoist")
			return "死牛鼻子";
		else
		{
			if( age < 20 ) return "小王八蛋";
			if( age < 50 ) return "臭贼";
			else return "老匹夫";
		}
	}
}


const char * query_self(CChar * ob)
{
	int age;
	string cla;
	const char * str;

	str = ob->querystr("rank_info/self");
	if(str[0]) return str;
		
	age = ob->query("age");
	cla = ob->querystr("class");
	
	if(EQUALSTR(ob->querystr("gender"), "女性"))
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "贫尼";
			else return "老尼";
		}
		else
		{
			if( age < 30 ) return "小女子";
			else return "妾身";
		}
	}
	else
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "贫僧";
			else return "老纳";
		}
		else if(cla == "taoist")
			return "贫道";
		else
		{
			if( age < 50 ) return "在下";
			else return "老头子";
		}
	}
}

const char * query_self_rude(CChar * ob)
{
	int age;
	string cla;
	const char * str;

	str = ob->querystr("rank_info/self_rude");
	if(str[0]) return str;

	age = ob->query("age");
	cla = ob->querystr("class");

	if(EQUALSTR(ob->querystr("gender"), "女性"))
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "贫尼";
			else return "老尼";
		}
		else
		{
			if( age < 30 ) return "本姑娘";
			else return "老娘";
		}
	}
	else
	{
		if(cla =="bonze")
		{
			if( age < 50 ) return "大和尚我";
			else return "老和尚我";
		}
		else if(cla == "taoist")
			return "本山人";
		else
		{
			if( age < 50 ) return "大爷我";
			else return "老子";
		}
	}
}

const char * query_close(CChar * me, CChar * ob)
{
    int a1, a2;

	if(ob)
	{
		if ((a2 = ob->query("mud_age")))
        	a1 = me->query("mud_age");
    	else 
		{ 	
	 		a1 = me->query("age");
			a2 = ob->query("age");
		}
	}
	else 
	{	
	 	a1 = me->query("age");
	 	a2 = 0;
	}
							
    if( EQUALSTR(ob->querystr("gender"), "女性"))
	{
        if (a1 >= a2)
             return "妹妹";
        else
             return "姐姐";
	}
	else
	{
		if (a1 >= a2)
             return "弟弟";
        else
             return "哥哥";
    }
}

const char * query_self_close(CChar * me, CChar * ob)
{
    int a1, a2;

	if (ob)
	{
      	if ( (a2 = ob->query("mud_age")) )
           	a1 = me->query("mud_age");
       	else 
       	{ 	
	      	a1 = me->query("age");
			a2 = ob->query("age");
		}
	} 
	else 
	{	
     	a1 = me->query("age");
       	a2 = 0;
	}
		
    if(EQUALSTR(me->querystr("gender"), "女性"))
	{
        if (a1 >= a2)
            return "姐姐我";
		else
            return "小妹我";
	}
    else
	{
		if (a1 >= a2)
			return "愚兄我";
        else
            return "小弟我";
	}

	return "Rank error!";
}

const char * query_waimao(string gender, int per)
{
	if ( gender == "男性"||gender == "无性" ) 
	{
		switch(per)
		{
			case 39: return "现在神清气爽，骨格清奇，宛若仙人。";
			case 38: return "现在丰神俊朗，长身玉立，宛如玉树临风。";
			case 37: return "现在飘逸出尘，潇洒绝伦。";
			case 36: return "现在面如美玉，粉妆玉琢，俊美不凡。";
			case 35: return "现在丰神如玉，目似朗星，令人过目难忘。";
			case 34: return "现在粉面朱唇，身姿俊俏，举止风流无限。";
			case 33: return "现在双目如星，眉梢传情，所见者无不为之心动。";
			case 32: return "现在举动如行云游水，独蕴风情，吸引所有异性目光。";
			case 31: return "现在双眼光华莹润，透出摄人心魄的光芒。";
			case 30: return "生得英俊潇洒，风流倜傥。";
			case 29: return "生得目似点漆，高大挺俊，令人心动。";
			case 28: return "生得面若秋月，儒雅斯文，举止适度。";
			case 27: return "生得剑眉星目，英姿勃勃，仪表不凡。";
			case 26: return "生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。";
			case 25: return "生得眉如双剑，眼如明星，英挺出众。";
			case 24: return "生得虎背熊腰，壮健有力，英姿勃发。";
			case 23: return "生得肤色白皙，红唇墨发，斯文有礼。";
			case 22: return "生得浓眉大眼，高大挺拔，气宇轩昂。";
			case 21: return "生得鼻直口方，线条分明，显出刚毅性格。";
			case 20: return "生得眉目清秀，端正大方，一表人才。";
			case 19: return "生得腰圆背厚，面阔口方，骨格不凡。";
			case 18: return "生得相貌平平，不会给人留下什么印相。";
			case 17: return "生得膀大腰圆，满脸横肉，恶形恶相。";
			case 16: return "生得獐头鼠须，让人一看就不生好感。";
			case 15: return "生得面颊深陷，瘦如枯骨，让人要发恶梦。";
			case 14: return "生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。";
			case 13: return "生得贼眉鼠眼，身高三尺，宛若猴状。";
			case 12: return "生得面如桔皮，头肿如猪，让人不想再看第二眼。";
			case 11: return "生得呲牙咧嘴，黑如锅底，奇丑无比。";
			default:
				if (per <= 10 ) return "生得眉歪眼斜，瘌头癣脚，不象人样。";
				if (per >= 40 ) return "现在一派神人气度，仙风道骨，举止出尘。";
		}
	}

	if ( gender == "女性")
	{
		switch(per)
		{
			case 39: return "现在美若天仙，不沾一丝烟尘。";
			case 38: return "现在灿若明霞，宝润如玉，恍如神妃仙子。";
			case 37: return "现在气质美如兰，才华馥比山，令人见之忘俗。";
			case 36: return "现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。";
			case 35: return "现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。";
			case 34: return "现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。";
			case 33: return "现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。";
			case 32: return "现在眉目如画，肌肤胜雪，真可谓闭月羞花。";
			case 31: return "现在娇若春花，媚如秋月，真的能沉鱼落雁。。";
			case 30: return "生得闲静如姣花照水，行动似弱柳扶风，体态万千。";
			case 29: return "生得娇小玲珑，宛如飞燕再世，楚楚动人。";
			case 28: return "生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。";
			case 27: return "生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。";
			case 26: return "生得丰胸细腰，妖娆多姿，让人一看就心跳不已。";
			case 25: return "生得粉嫩白至，如芍药笼烟，雾里看花。";
			case 24: return "生得腮凝新荔，目若秋水，千娇百媚。";
			case 23: return "生得鲜艳妍媚，肌肤莹透，引人遐思。";
			case 22: return "生得巧笑嫣然，宛约可人。";
			case 21: return "生得如梨花带露，清新秀丽。";
			case 20: return "生得风姿楚楚，明丽动人。";
			case 19: return "生得肌肤微丰，雅淡温宛，清新可人。";
			case 18: return "生得虽不标致，倒也白净，有些动人之处。";
			case 17: return "生得身材瘦小，肌肤无光，两眼无神。";
			case 16: return "生得干黄枯瘦，脸色腊黄，毫无女人味。";
			case 15: return "生得满脸疙瘩，皮色粗黑，丑陋不堪。";
			case 14: return "生得一嘴大暴牙，让人一看就没好感。";
			case 13: return "生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。";
			case 12: return "生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。";
			case 11: return "生得歪鼻斜眼，脸色灰败，直如鬼怪一般。";
			default:
				if (per >= 40) return "现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物";
				if (per <= 10) return "生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。";
		}
	}

	return "";
}